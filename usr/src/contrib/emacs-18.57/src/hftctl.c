begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* IBM has disclaimed copyright on this module.  */
end_comment

begin_comment
comment|/***************************************************************/
end_comment

begin_comment
comment|/*                                                             */
end_comment

begin_comment
comment|/* Function: hftctl                                            */
end_comment

begin_comment
comment|/*                                                             */
end_comment

begin_comment
comment|/* Syntax:                                                     */
end_comment

begin_comment
comment|/*    #include<sys/ioctl.h>                                   */
end_comment

begin_comment
comment|/*    #include<sys/hft.h>                                     */
end_comment

begin_comment
comment|/*                                                             */
end_comment

begin_comment
comment|/*    int hftctl(fildes, request, arg )                        */
end_comment

begin_comment
comment|/*    int fildes, request;                                     */
end_comment

begin_comment
comment|/*    char *arg;                                               */
end_comment

begin_comment
comment|/*                                                             */
end_comment

begin_comment
comment|/* Description:                                                */
end_comment

begin_comment
comment|/*                                                             */
end_comment

begin_comment
comment|/*    Does the following:                                      */
end_comment

begin_comment
comment|/*      1. determines if fildes is pty                         */
end_comment

begin_comment
comment|/*         does normal ioctl it is not                         */
end_comment

begin_comment
comment|/*      2. places fildes into raw mode                         */
end_comment

begin_comment
comment|/*      3. converts ioctl arguments to datastream              */
end_comment

begin_comment
comment|/*      4. waits for 2 secs for acknowledgement before         */
end_comment

begin_comment
comment|/*         timimg out.                                         */
end_comment

begin_comment
comment|/*      5. places response in callers buffer ( just like       */
end_comment

begin_comment
comment|/*         ioctl.                                              */
end_comment

begin_comment
comment|/*      6. returns fildes to its original mode                 */
end_comment

begin_comment
comment|/*                                                             */
end_comment

begin_comment
comment|/*    User of this program should review steps 1,4, and 3.     */
end_comment

begin_comment
comment|/*    hftctl makes no check on the request type. It must be    */
end_comment

begin_comment
comment|/*    a HFT ioctl that is supported remotely.                  */
end_comment

begin_comment
comment|/*    This program will use the SIGALRM and alarm(2).  Any     */
end_comment

begin_comment
comment|/*    Previous alarms are lost.                                */
end_comment

begin_comment
comment|/*                                                             */
end_comment

begin_comment
comment|/*    Users of this program are free to modify it any way      */
end_comment

begin_comment
comment|/*    they want.                                               */
end_comment

begin_comment
comment|/*                                                             */
end_comment

begin_comment
comment|/* Return Value:                                               */
end_comment

begin_comment
comment|/*                                                             */
end_comment

begin_comment
comment|/*    If ioctl fails, a value of -1 is returned and errno      */
end_comment

begin_comment
comment|/*    is set to indicate the error.                            */
end_comment

begin_comment
comment|/*                                                             */
end_comment

begin_comment
comment|/***************************************************************/
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/devinfo.h>
end_include

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_include
include|#
directive|include
file|<termio.h>
end_include

begin_include
include|#
directive|include
file|<sys/hft.h>
end_include

begin_include
include|#
directive|include
file|<sys/tty.h>
end_include

begin_comment
comment|/* #include<sys/pty.h> */
end_comment

begin_define
define|#
directive|define
name|REMOTE
value|0x01
end_define

begin_undef
undef|#
directive|undef
name|ioctl
end_undef

begin_decl_stmt
specifier|static
name|char
name|SCCSid
index|[]
init|=
literal|"com/gnuemacs/src,3.1,9021-90/05/03-5/3/90"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*************** LOCAL DEFINES **********************************/
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|FUNC
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_comment
comment|/* pointer to a function        */
end_comment

begin_define
define|#
directive|define
name|QDEV
value|((HFQPDEVCH<<8)|HFQPDEVCL)
end_define

begin_define
define|#
directive|define
name|QLOC
value|((HFQLOCCH<<8)|HFQLOCCL)
end_define

begin_define
define|#
directive|define
name|QPS
value|((HFQPRESCH<<8)|HFQPRESCL)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TCGETS
end_ifndef

begin_define
define|#
directive|define
name|TCGETS
value|TCGETA
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TCSETS
end_ifndef

begin_define
define|#
directive|define
name|TCSETS
value|TCSETA
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*************** EXTERNAL / GLOBAL DATA AREA ********************/
end_comment

begin_function_decl
name|int
name|hfqry
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hfskbd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|jmp_buf
name|hftenv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|is_ack_vtd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|FUNC
name|sav_alrm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|hfctlreq
name|req
init|=
block|{
literal|0x1b
block|,
literal|'['
block|,
literal|'x'
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|21
block|,
name|HFCTLREQCH
block|,
name|HFCTLREQCL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|hfctlack
name|ACK
init|=
block|{
literal|0x1b
block|,
literal|'['
block|,
literal|'x'
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|21
block|,
name|HFCTLACKCH
block|,
name|HFCTLACKCL
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* FUNC             signal(); */
end_comment

begin_comment
comment|/*************** LOCAL MACROS ***********************************/
end_comment

begin_define
define|#
directive|define
name|HFTYPE
parameter_list|(
name|p
parameter_list|)
value|((p->hf_typehi<<8)|(p->hf_typelo))
end_define

begin_define
define|#
directive|define
name|BYTE4
parameter_list|(
name|p
parameter_list|)
value|((p)[0]<<24 | (p)[1]<<16 | (p)[2]<<8 | (p)[3])
end_define

begin_comment
comment|/* read a buffer        */
end_comment

begin_define
define|#
directive|define
name|RD_BUF
parameter_list|(
name|f
parameter_list|,
name|p
parameter_list|,
name|l
parameter_list|)
define|\
value|while ((l)) \           if ((j = read((f),(p),(l)))< 0) \              if (errno != EINTR) return (-1); \              else continue; \           else { (l) -= j; (p) += j; }
end_define

begin_comment
comment|/*************** function prototypes ***************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_expr_stmt
specifier|static
name|GT_ACK
argument_list|(
argument|int fd
argument_list|,
argument|int req
argument_list|,
argument|char *buf
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|WR_REQ
argument_list|(
argument|int fd
argument_list|,
argument|int request
argument_list|,
argument|int cmdlen
argument_list|,
argument|char *cmd
argument_list|,
argument|int resplen
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|hft_alrm
argument_list|(
argument|int sig
argument_list|)
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_expr_stmt
specifier|static
name|GT_ACK
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|WR_REQ
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|hft_alrm
argument_list|()
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*************** HFTCTL FUNCTION *******************************/
end_comment

begin_macro
name|hftctl
argument_list|(
argument|fd
argument_list|,
argument|request
argument_list|,
argument|arg
argument_list|)
end_macro

begin_decl_stmt
name|int
name|fd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|request
decl_stmt|;
end_decl_stmt

begin_union
union|union
block|{
name|struct
name|hfintro
modifier|*
name|intro
decl_stmt|;
name|struct
name|hfquery
modifier|*
name|query
decl_stmt|;
name|char
modifier|*
name|c
decl_stmt|;
block|}
name|arg
union|;
end_union

begin_block
block|{
name|int
name|i
decl_stmt|;
name|int
name|fd_flag
decl_stmt|;
comment|/* fcntl flags          */
specifier|register
union|union
block|{
name|struct
name|hfintro
modifier|*
name|cmd
decl_stmt|;
comment|/* p.cmd - intro des.   */
name|struct
name|hfqphdevc
modifier|*
name|ph
decl_stmt|;
comment|/* p.ph  - physical dev.*/
name|char
modifier|*
name|c
decl_stmt|;
comment|/* p.c   - char ptr     */
block|}
name|p
union|;
comment|/* general pointer      */
name|int
name|pty_new
decl_stmt|;
comment|/* pty modes            */
name|int
name|pty_old
decl_stmt|;
name|int
name|retcode
decl_stmt|;
name|struct
name|termios
name|term_new
decl_stmt|;
comment|/* terminal attributes  */
name|struct
name|termios
name|term_old
decl_stmt|;
name|struct
name|devinfo
name|devInfo
decl_stmt|;
comment|/* defined in sys/devinfo.h */
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|IOCINFO
argument_list|,
operator|&
name|devInfo
argument_list|)
operator|==
operator|-
literal|1
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|devInfo
operator|.
name|devtype
operator|!=
name|DD_PSEU
condition|)
comment|/* is it a pty? */
return|return
operator|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|request
argument_list|,
name|arg
argument_list|)
operator|)
return|;
comment|/* no, do IOCTL */
comment|/******* START PTY **************/
comment|/**  Pty found, possible HFT    */
comment|/** set new file des as raw     */
comment|/** as you can.                 */
comment|/********************************/
comment|/* Get current state of file    */
comment|/* descriptor& save            */
if|if
condition|(
operator|(
name|fd_flag
operator|=
name|fcntl
argument_list|(
name|fd
argument_list|,
name|F_GETFL
argument_list|,
literal|0
argument_list|)
operator|)
operator|==
operator|-
literal|1
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|TCGETS
argument_list|,
operator|&
name|term_old
argument_list|)
operator|==
operator|-
literal|1
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* set terminal attr to raw     */
comment|/* and to delay on read         */
name|pty_new
operator|=
name|pty_old
operator||
name|REMOTE
expr_stmt|;
name|memcpy
argument_list|(
operator|&
name|term_new
argument_list|,
operator|&
name|term_old
argument_list|,
sizeof|sizeof
argument_list|(
name|term_new
argument_list|)
argument_list|)
expr_stmt|;
name|term_new
operator|.
name|c_iflag
operator|=
literal|0
expr_stmt|;
name|term_new
operator|.
name|c_oflag
operator|=
literal|0
expr_stmt|;
name|term_new
operator|.
name|c_lflag
operator|=
literal|0
expr_stmt|;
comment|/* term_new.c_line  = 0; */
for|for
control|(
name|i
operator|=
literal|1
init|;
name|i
operator|<=
literal|5
condition|;
name|i
operator|++
control|)
name|term_new
operator|.
name|c_cc
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
name|term_new
operator|.
name|c_cc
index|[
literal|0
index|]
operator|=
operator|-
literal|1
expr_stmt|;
name|ioctl
argument_list|(
name|fd
argument_list|,
name|TCSETS
argument_list|,
operator|&
name|term_new
argument_list|)
expr_stmt|;
if|if
condition|(
name|fcntl
argument_list|(
name|fd
argument_list|,
name|F_SETFL
argument_list|,
name|fd_flag
operator|&
operator|~
name|O_NDELAY
argument_list|)
operator|==
operator|-
literal|1
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* call spacific function       */
if|if
condition|(
name|request
operator|==
name|HFSKBD
condition|)
name|retcode
operator|=
name|hfskbd
argument_list|(
name|fd
argument_list|,
name|request
argument_list|,
name|arg
operator|.
name|c
argument_list|)
expr_stmt|;
else|else
comment|/* assume HFQUERY */
name|retcode
operator|=
name|hfqry
argument_list|(
name|fd
argument_list|,
name|request
argument_list|,
name|arg
operator|.
name|c
argument_list|)
expr_stmt|;
name|fcntl
argument_list|(
name|fd
argument_list|,
name|F_SETFL
argument_list|,
name|fd_flag
argument_list|)
expr_stmt|;
comment|/* reset terminal to original   */
name|ioctl
argument_list|(
name|fd
argument_list|,
name|TCSETS
argument_list|,
operator|&
name|term_old
argument_list|)
expr_stmt|;
return|return
operator|(
name|retcode
operator|)
return|;
comment|/* return error                 */
block|}
end_block

begin_comment
comment|/*************** HFSKBD  FUNCTION ******************************/
end_comment

begin_function
specifier|static
name|int
name|hfskbd
parameter_list|(
name|fd
parameter_list|,
name|request
parameter_list|,
name|arg
parameter_list|)
name|int
name|fd
decl_stmt|;
name|int
name|request
decl_stmt|;
name|struct
name|hfbuf
modifier|*
name|arg
decl_stmt|;
block|{
name|WR_REQ
argument_list|(
name|fd
argument_list|,
name|request
argument_list|,
name|arg
operator|->
name|hf_buflen
argument_list|,
name|arg
operator|->
name|hf_bufp
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
name|GT_ACK
argument_list|(
name|fd
argument_list|,
name|request
argument_list|,
name|arg
operator|->
name|hf_bufp
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*************** HFQUERY FUNCTION ******************************/
end_comment

begin_function
specifier|static
name|int
name|hfqry
parameter_list|(
name|fd
parameter_list|,
name|request
parameter_list|,
name|arg
parameter_list|)
name|int
name|fd
decl_stmt|;
name|int
name|request
decl_stmt|;
name|struct
name|hfquery
modifier|*
name|arg
decl_stmt|;
block|{
name|WR_REQ
argument_list|(
name|fd
argument_list|,
name|request
argument_list|,
name|arg
operator|->
name|hf_cmdlen
argument_list|,
name|arg
operator|->
name|hf_cmd
argument_list|,
name|arg
operator|->
name|hf_resplen
argument_list|)
expr_stmt|;
return|return
operator|(
name|GT_ACK
argument_list|(
name|fd
argument_list|,
name|request
argument_list|,
name|arg
operator|->
name|hf_resp
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*************** GT_ACK FUNCTION ******************************/
end_comment

begin_function
specifier|static
name|int
name|GT_ACK
parameter_list|(
name|fd
parameter_list|,
name|req
parameter_list|,
name|buf
parameter_list|)
name|int
name|fd
decl_stmt|;
name|int
name|req
decl_stmt|;
name|char
modifier|*
name|buf
decl_stmt|;
block|{
name|struct
name|hfctlack
name|ack
decl_stmt|;
name|int
name|i
init|=
sizeof|sizeof
argument_list|(
name|ack
argument_list|)
decl_stmt|;
name|int
name|j
init|=
literal|0
decl_stmt|;
union|union
block|{
name|char
modifier|*
name|c
decl_stmt|;
name|struct
name|hfctlack
modifier|*
name|ack
decl_stmt|;
block|}
name|p
union|;
name|is_ack_vtd
operator|=
literal|0
expr_stmt|;
comment|/* flag no ACT VTD yet         */
if|if
condition|(
name|setjmp
argument_list|(
name|hftenv
argument_list|)
condition|)
comment|/* set environment in case     */
block|{
comment|/* of time out                 */
name|errno
operator|=
name|ENODEV
expr_stmt|;
comment|/* if time out, set errno      */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* flag error                  */
block|}
name|alarm
argument_list|(
literal|3
argument_list|)
expr_stmt|;
comment|/* time out in 3 secs          */
name|sav_alrm
operator|=
operator|(
name|FUNC
operator|)
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|hft_alrm
argument_list|)
expr_stmt|;
comment|/* prepare to catch time out */
name|p
operator|.
name|ack
operator|=
operator|&
name|ack
expr_stmt|;
while|while
condition|(
operator|!
name|is_ack_vtd
condition|)
comment|/* do until valid ACK VTD      */
block|{
name|RD_BUF
argument_list|(
name|fd
argument_list|,
name|p
operator|.
name|c
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|/* read until a ACK VTD is fill*/
if|if
condition|(
operator|!
name|memcmp
argument_list|(
operator|&
name|ack
argument_list|,
operator|&
name|ACK
argument_list|,
sizeof|sizeof
argument_list|(
name|HFINTROSZ
argument_list|)
argument_list|)
comment|/* the ACK intro&  */
operator|&&
operator|(
name|ack
operator|.
name|hf_request
operator|==
name|req
operator|)
condition|)
comment|/* is it the response we want ?*/
block|{
comment|/* yes, ACK VTD found          */
name|is_ack_vtd
operator|=
literal|1
expr_stmt|;
comment|/* quickly, flag it            */
break|break;
comment|/* get the %$%#@ out of here   */
block|}
name|p
operator|.
name|ack
operator|=
operator|&
name|ack
expr_stmt|;
comment|/* no, then skip 1st           */
operator|++
name|p
operator|.
name|c
expr_stmt|;
comment|/* char and start over         */
name|i
operator|=
sizeof|sizeof
argument_list|(
name|ack
argument_list|)
operator|-
literal|1
expr_stmt|;
comment|/* one less ESC to cry over    */
while|while
condition|(
operator|(
operator|*
name|p
operator|.
name|c
operator|!=
literal|0x1b
operator|)
operator|&&
name|i
condition|)
comment|/* scan for next ESC           */
block|{
operator|++
name|p
operator|.
name|c
expr_stmt|;
operator|--
name|i
expr_stmt|;
block|}
comment|/* if any                      */
operator|(
name|i
condition|?
name|memcpy
argument_list|(
operator|&
name|ack
argument_list|,
name|p
operator|.
name|c
argument_list|,
name|i
argument_list|)
else|:
literal|0
operator|)
expr_stmt|;
comment|/* if any left over, then move */
name|p
operator|.
name|ack
operator|=
operator|&
name|ack
expr_stmt|;
comment|/* ESC to front of ack struct  */
name|p
operator|.
name|c
operator|+=
name|i
expr_stmt|;
comment|/* skip over whats been read   */
name|i
operator|=
sizeof|sizeof
argument_list|(
name|ack
argument_list|)
operator|-
name|i
expr_stmt|;
comment|/* set whats left to be read   */
block|}
comment|/***** TRY AGAIN               */
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* ACK VTD received, reset alrm*/
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|sav_alrm
argument_list|)
expr_stmt|;
comment|/* reset signal                */
if|if
condition|(
name|i
operator|=
name|ack
operator|.
name|hf_arg_len
condition|)
comment|/* any data following ?        */
block|{
comment|/* yes,                        */
name|RD_BUF
argument_list|(
name|fd
argument_list|,
name|buf
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|/* read until it is received   */
block|}
if|if
condition|(
name|errno
operator|=
name|ack
operator|.
name|hf_retcode
condition|)
comment|/* set errno based on returned */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* code, if 0, then no error   */
else|else
return|return
operator|(
literal|0
operator|)
return|;
comment|/* if set, then error returned */
block|}
end_function

begin_comment
comment|/*************** HFT_ALRM FUNCTION ******************************/
end_comment

begin_function
specifier|static
name|int
name|hft_alrm
parameter_list|(
name|sig
parameter_list|)
comment|/* Function hft_alrm - handle  */
name|int
name|sig
decl_stmt|;
comment|/* alarm signal               */
block|{
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|sav_alrm
argument_list|)
expr_stmt|;
comment|/* reset to previous          */
if|if
condition|(
name|is_ack_vtd
condition|)
comment|/* has ack vtd arrived ?      */
return|return
operator|(
literal|0
operator|)
return|;
comment|/* yes, then continue         */
else|else
comment|/* no, then return with error */
name|longjmp
argument_list|(
name|hftenv
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*********************************************************************/
end_comment

begin_comment
comment|/***                                                               ***/
end_comment

begin_comment
comment|/***  NOTE: Both the HFCTLREQ and the arg structure should be      ***/
end_comment

begin_comment
comment|/***        sent in one io write operation.  If terminal           ***/
end_comment

begin_comment
comment|/***        emulators are in NODELAY mode then multiple writes     ***/
end_comment

begin_comment
comment|/***        may cause bogus information to be read by the emulator ***/
end_comment

begin_comment
comment|/***        depending on the timing.                               ***/
end_comment

begin_comment
comment|/***                                                               ***/
end_comment

begin_comment
comment|/*********************************************************************/
end_comment

begin_function
specifier|static
name|int
name|WR_REQ
parameter_list|(
name|fd
parameter_list|,
name|request
parameter_list|,
name|cmdlen
parameter_list|,
name|cmd
parameter_list|,
name|resplen
parameter_list|)
name|int
name|fd
decl_stmt|;
name|int
name|request
decl_stmt|;
name|int
name|cmdlen
decl_stmt|;
name|char
modifier|*
name|cmd
decl_stmt|;
name|int
name|resplen
decl_stmt|;
block|{
struct|struct
block|{
name|char
modifier|*
name|c
decl_stmt|;
name|struct
name|hfctlreq
modifier|*
name|req
decl_stmt|;
block|}
name|p
struct|;
name|int
name|size
decl_stmt|;
name|req
operator|.
name|hf_request
operator|=
name|request
expr_stmt|;
name|req
operator|.
name|hf_arg_len
operator|=
name|cmdlen
expr_stmt|;
name|req
operator|.
name|hf_rsp_len
operator|=
name|resplen
expr_stmt|;
if|if
condition|(
name|cmdlen
condition|)
comment|/* if arg structure to pass    */
block|{
name|size
operator|=
sizeof|sizeof
argument_list|(
expr|struct
name|hfctlreq
argument_list|)
operator|+
name|cmdlen
expr_stmt|;
if|if
condition|(
operator|(
name|p
operator|.
name|c
operator|=
name|malloc
argument_list|(
name|size
argument_list|)
operator|)
operator|==
name|NULL
condition|)
comment|/* malloc one area            */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|memcpy
argument_list|(
name|p
operator|.
name|c
argument_list|,
operator|&
name|req
argument_list|,
sizeof|sizeof
argument_list|(
name|req
argument_list|)
argument_list|)
expr_stmt|;
comment|/* copy CTL REQ struct         */
name|memcpy
argument_list|(
name|p
operator|.
name|c
operator|+
sizeof|sizeof
argument_list|(
name|req
argument_list|)
argument_list|,
name|cmd
argument_list|,
name|cmdlen
argument_list|)
expr_stmt|;
comment|/* copy arg struct     */
block|}
else|else
block|{
name|p
operator|.
name|req
operator|=
operator|&
name|req
expr_stmt|;
comment|/* otherwise use only CTL REQ  */
name|size
operator|=
sizeof|sizeof
argument_list|(
name|req
argument_list|)
expr_stmt|;
block|}
comment|/* write request to terminal   */
if|if
condition|(
name|write
argument_list|(
name|fd
argument_list|,
name|p
operator|.
name|c
argument_list|,
name|size
argument_list|)
operator|==
operator|-
literal|1
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|p
operator|.
name|req
operator|!=
operator|&
name|req
condition|)
comment|/* free if allocated           */
name|free
argument_list|(
name|p
operator|.
name|c
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

