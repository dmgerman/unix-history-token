begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997, 1998, 1999 Nicolas Souchu, Michael Smith  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_include
include|#
directive|include
file|"ppi.h"
end_include

begin_if
if|#
directive|if
name|NPPI
operator|>
literal|0
end_if

begin_include
include|#
directive|include
file|"opt_ppb_1284.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<sys/fcntl.h>
end_include

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<dev/ppbus/ppbconf.h>
end_include

begin_include
include|#
directive|include
file|<dev/ppbus/ppb_msq.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|PERIPH_1284
end_ifdef

begin_include
include|#
directive|include
file|<dev/ppbus/ppb_1284.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<dev/ppbus/ppi.h>
end_include

begin_include
include|#
directive|include
file|"ppbus_if.h"
end_include

begin_include
include|#
directive|include
file|<dev/ppbus/ppbio.h>
end_include

begin_define
define|#
directive|define
name|BUFSIZE
value|512
end_define

begin_struct
struct|struct
name|ppi_data
block|{
name|int
name|ppi_unit
decl_stmt|;
name|int
name|ppi_flags
decl_stmt|;
define|#
directive|define
name|HAVE_PPBUS
value|(1<<0)
define|#
directive|define
name|HAD_PPBUS
value|(1<<1)
name|int
name|ppi_count
decl_stmt|;
name|int
name|ppi_mode
decl_stmt|;
comment|/* IEEE1284 mode */
name|char
name|ppi_buffer
index|[
name|BUFSIZE
index|]
decl_stmt|;
name|struct
name|resource
modifier|*
name|intr_resource
decl_stmt|;
comment|/* interrupt resource */
name|void
modifier|*
name|intr_cookie
decl_stmt|;
comment|/* interrupt registration cookie */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DEVTOSOFTC
parameter_list|(
name|dev
parameter_list|)
define|\
value|((struct ppi_data *)device_get_softc(dev))
end_define

begin_define
define|#
directive|define
name|UNITOSOFTC
parameter_list|(
name|unit
parameter_list|)
define|\
value|((struct ppi_data *)devclass_get_softc(ppi_devclass, (unit)))
end_define

begin_define
define|#
directive|define
name|UNITODEVICE
parameter_list|(
name|unit
parameter_list|)
define|\
value|(devclass_get_device(ppi_devclass, (unit)))
end_define

begin_function_decl
specifier|static
name|int
name|ppi_probe
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|ppi_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ppiintr
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|devclass_t
name|ppi_devclass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|device_method_t
name|ppi_methods
index|[]
init|=
block|{
comment|/* device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|ppi_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|ppi_attach
argument_list|)
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|driver_t
name|ppi_driver
init|=
block|{
literal|"ppi"
block|,
name|ppi_methods
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|ppi_data
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_open_t
name|ppiopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_close_t
name|ppiclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_ioctl_t
name|ppiioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_write_t
name|ppiwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_read_t
name|ppiread
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CDEV_MAJOR
value|82
end_define

begin_decl_stmt
specifier|static
name|struct
name|cdevsw
name|ppi_cdevsw
init|=
block|{
comment|/* open */
name|ppiopen
block|,
comment|/* close */
name|ppiclose
block|,
comment|/* read */
name|ppiread
block|,
comment|/* write */
name|ppiwrite
block|,
comment|/* ioctl */
name|ppiioctl
block|,
comment|/* poll */
name|nopoll
block|,
comment|/* mmap */
name|nommap
block|,
comment|/* strategy */
name|nostrategy
block|,
comment|/* name */
literal|"ppi"
block|,
comment|/* maj */
name|CDEV_MAJOR
block|,
comment|/* dump */
name|nodump
block|,
comment|/* psize */
name|nopsize
block|,
comment|/* flags */
literal|0
block|,
comment|/* bmaj */
operator|-
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|PERIPH_1284
end_ifdef

begin_function
specifier|static
name|void
name|ppi_enable_intr
parameter_list|(
name|device_t
name|ppidev
parameter_list|)
block|{
name|char
name|r
decl_stmt|;
name|device_t
name|ppbus
init|=
name|device_get_parent
argument_list|(
name|ppidev
argument_list|)
decl_stmt|;
name|r
operator|=
name|ppb_rctr
argument_list|(
name|ppbus
argument_list|)
expr_stmt|;
name|ppb_wctr
argument_list|(
name|ppbus
argument_list|,
name|r
operator||
name|IRQENABLE
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_function
specifier|static
name|void
name|ppi_disable_intr
parameter_list|(
name|device_t
name|ppidev
parameter_list|)
block|{
name|char
name|r
decl_stmt|;
name|device_t
name|ppbus
init|=
name|device_get_parent
argument_list|(
name|ppidev
argument_list|)
decl_stmt|;
name|r
operator|=
name|ppb_rctr
argument_list|(
name|ppbus
argument_list|)
expr_stmt|;
name|ppb_wctr
argument_list|(
name|ppbus
argument_list|,
name|r
operator|&
operator|~
name|IRQENABLE
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PERIPH_1284 */
end_comment

begin_comment
comment|/*  * ppi_probe()  */
end_comment

begin_function
specifier|static
name|int
name|ppi_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|ppi_data
modifier|*
name|ppi
decl_stmt|;
specifier|static
name|int
name|once
decl_stmt|;
comment|/* probe is always ok */
name|device_set_desc
argument_list|(
name|dev
argument_list|,
literal|"Parallel I/O"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|once
operator|++
condition|)
name|cdevsw_add
argument_list|(
operator|&
name|ppi_cdevsw
argument_list|)
expr_stmt|;
name|ppi
operator|=
name|DEVTOSOFTC
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
name|ppi
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|ppi_data
argument_list|)
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
comment|/*  * ppi_attach()  */
end_comment

begin_function
specifier|static
name|int
name|ppi_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|uintptr_t
name|irq
decl_stmt|;
name|int
name|zero
init|=
literal|0
decl_stmt|;
name|struct
name|ppi_data
modifier|*
name|ppi
init|=
name|DEVTOSOFTC
argument_list|(
name|dev
argument_list|)
decl_stmt|;
comment|/* retrive the irq */
name|BUS_READ_IVAR
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|PPBUS_IVAR_IRQ
argument_list|,
operator|&
name|irq
argument_list|)
expr_stmt|;
comment|/* declare our interrupt handler */
name|ppi
operator|->
name|intr_resource
operator|=
name|bus_alloc_resource
argument_list|(
name|dev
argument_list|,
name|SYS_RES_IRQ
argument_list|,
operator|&
name|zero
argument_list|,
name|irq
argument_list|,
name|irq
argument_list|,
literal|1
argument_list|,
name|RF_ACTIVE
argument_list|)
expr_stmt|;
name|make_dev
argument_list|(
operator|&
name|ppi_cdevsw
argument_list|,
name|device_get_unit
argument_list|(
name|dev
argument_list|)
argument_list|,
comment|/* XXX cleanup */
name|UID_ROOT
argument_list|,
name|GID_WHEEL
argument_list|,
literal|0600
argument_list|,
literal|"ppi%d"
argument_list|,
name|device_get_unit
argument_list|(
name|dev
argument_list|)
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
comment|/*  * Cable  * -----  *  * Use an IEEE1284 compliant (DB25/DB25) cable with the following tricks:  *  * nStrobe<-> nAck		1<-> 10  * nAutofd<-> Busy		11<-> 14  * nSelectin<-> Select		17<-> 13  * nInit<-> nFault		15<-> 16  *  */
end_comment

begin_function
specifier|static
name|void
name|ppiintr
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|PERIPH_1284
name|device_t
name|ppidev
init|=
operator|(
name|device_t
operator|)
name|arg
decl_stmt|;
name|device_t
name|ppbus
init|=
name|device_get_parent
argument_list|(
name|ppidev
argument_list|)
decl_stmt|;
name|struct
name|ppi_data
modifier|*
name|ppi
init|=
name|DEVTOSOFTC
argument_list|(
name|ppidev
argument_list|)
decl_stmt|;
name|ppi_disable_intr
argument_list|(
name|ppidev
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|ppb_1284_get_state
argument_list|(
name|ppbus
argument_list|)
condition|)
block|{
comment|/* accept IEEE1284 negociation then wakeup an waiting process to 	 * continue negociation at process level */
case|case
name|PPB_FORWARD_IDLE
case|:
comment|/* Event 1 */
if|if
condition|(
operator|(
name|ppb_rstr
argument_list|(
name|ppbus
argument_list|)
operator|&
operator|(
name|SELECT
operator||
name|nBUSY
operator|)
operator|)
operator|==
operator|(
name|SELECT
operator||
name|nBUSY
operator|)
condition|)
block|{
comment|/* IEEE1284 negociation */
ifdef|#
directive|ifdef
name|DEBUG_1284
name|printf
argument_list|(
literal|"N"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* Event 2 - prepare for reading the ext. value */
name|ppb_wctr
argument_list|(
name|ppbus
argument_list|,
operator|(
name|PCD
operator||
name|STROBE
operator||
name|nINIT
operator|)
operator|&
operator|~
name|SELECTIN
argument_list|)
expr_stmt|;
name|ppb_1284_set_state
argument_list|(
name|ppbus
argument_list|,
name|PPB_NEGOCIATION
argument_list|)
expr_stmt|;
block|}
else|else
block|{
ifdef|#
directive|ifdef
name|DEBUG_1284
name|printf
argument_list|(
literal|"0x%x"
argument_list|,
name|ppb_rstr
argument_list|(
name|ppbus
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|ppb_peripheral_terminate
argument_list|(
name|ppbus
argument_list|,
name|PPB_DONTWAIT
argument_list|)
expr_stmt|;
break|break;
block|}
comment|/* wake up any process waiting for negociation from 		 * remote master host */
comment|/* XXX should set a variable to warn the process about 		 * the interrupt */
name|wakeup
argument_list|(
name|ppi
argument_list|)
expr_stmt|;
break|break;
default|default:
ifdef|#
directive|ifdef
name|DEBUG_1284
name|printf
argument_list|(
literal|"?%d"
argument_list|,
argument|ppb_1284_get_state(ppbus);
endif|#
directive|endif
argument|ppb_1284_set_state(ppbus, PPB_FORWARD_IDLE); 		ppb_set_mode(ppbus, PPB_COMPATIBLE); 		break; 	}  	ppi_enable_intr(ppidev);
endif|#
directive|endif
comment|/* PERIPH_1284 */
argument|return; }  static int ppiopen(dev_t dev, int flags, int fmt, struct proc *p) { 	u_int unit = minor(dev); 	struct ppi_data *ppi = UNITOSOFTC(unit); 	device_t ppidev = UNITODEVICE(unit);         device_t ppbus = device_get_parent(ppidev); 	int res;  	if (!ppi) 		return (ENXIO);  	if (!(ppi->ppi_flags& HAVE_PPBUS)) { 		if ((res = ppb_request_bus(ppbus, ppidev, 			(flags& O_NONBLOCK) ? PPB_DONTWAIT : 						(PPB_WAIT | PPB_INTR)))) 			return (res);  		ppi->ppi_flags |= HAVE_PPBUS;
comment|/* register our interrupt handler */
argument|BUS_SETUP_INTR(device_get_parent(ppidev), ppidev, ppi->intr_resource, 			       INTR_TYPE_TTY, ppiintr, dev,&ppi->intr_cookie); 	} 	ppi->ppi_count +=
literal|1
argument|;  	return (
literal|0
argument|); }  static int ppiclose(dev_t dev, int flags, int fmt, struct proc *p) { 	u_int unit = minor(dev); 	struct ppi_data *ppi = UNITOSOFTC(unit); 	device_t ppidev = UNITODEVICE(unit);         device_t ppbus = device_get_parent(ppidev);  	ppi->ppi_count --; 	if (!ppi->ppi_count) {
ifdef|#
directive|ifdef
name|PERIPH_1284
argument|switch (ppb_1284_get_state(ppbus)) { 		case PPB_PERIPHERAL_IDLE: 			ppb_peripheral_terminate(ppbus,
literal|0
argument|); 			break; 		case PPB_REVERSE_IDLE: 		case PPB_EPP_IDLE: 		case PPB_ECP_FORWARD_IDLE: 		default: 			ppb_1284_terminate(ppbus); 			break; 		}
endif|#
directive|endif
comment|/* PERIPH_1284 */
comment|/* unregistration of interrupt forced by release */
argument|ppb_release_bus(ppbus, ppidev);  		ppi->ppi_flags&= ~HAVE_PPBUS; 	}  	return (
literal|0
argument|); }
comment|/*  * ppiread()  *  * IEEE1284 compliant read.  *  * First, try negociation to BYTE then NIBBLE mode  * If no data is available, wait for it otherwise transfer as much as possible  */
argument|static int ppiread(dev_t dev, struct uio *uio, int ioflag) {
ifdef|#
directive|ifdef
name|PERIPH_1284
argument|u_int unit = minor(dev); 	struct ppi_data *ppi = UNITOSOFTC(unit); 	device_t ppidev = UNITODEVICE(unit);         device_t ppbus = device_get_parent(ppidev); 	int len
argument_list|,
argument|error =
literal|0
argument|;  	switch (ppb_1284_get_state(ppbus)) { 	case PPB_PERIPHERAL_IDLE: 		ppb_peripheral_terminate(ppbus,
literal|0
argument|);
comment|/* fall throught */
argument|case PPB_FORWARD_IDLE:
comment|/* if can't negociate NIBBLE mode then try BYTE mode, 		 * the peripheral may be a computer 		 */
argument|if ((ppb_1284_negociate(ppbus, 			ppi->ppi_mode = PPB_NIBBLE,
literal|0
argument|))) {
comment|/* XXX Wait 2 seconds to let the remote host some 			 * time to terminate its interrupt 			 */
argument|tsleep(ppi, PPBPRI,
literal|"ppiread"
argument|,
literal|2
argument|*hz); 			 			if ((error = ppb_1284_negociate(ppbus, 				ppi->ppi_mode = PPB_BYTE,
literal|0
argument|))) 				return (error); 		} 		break;  	case PPB_REVERSE_IDLE: 	case PPB_EPP_IDLE: 	case PPB_ECP_FORWARD_IDLE: 	default: 		break; 	}
ifdef|#
directive|ifdef
name|DEBUG_1284
argument|printf(
literal|"N"
argument|);
endif|#
directive|endif
comment|/* read data */
argument|len =
literal|0
argument|; 	while (uio->uio_resid) { 		if ((error = ppb_1284_read(ppbus, ppi->ppi_mode, 			ppi->ppi_buffer, min(BUFSIZE, uio->uio_resid),&len))) { 			goto error; 		}  		if (!len) 			goto error;
comment|/* no more data */
ifdef|#
directive|ifdef
name|DEBUG_1284
argument|printf(
literal|"d"
argument|);
endif|#
directive|endif
argument|if ((error = uiomove(ppi->ppi_buffer, len, uio))) 			goto error; 	}  error:
else|#
directive|else
comment|/* PERIPH_1284 */
argument|int error = ENODEV;
endif|#
directive|endif
argument|return (error); }
comment|/*  * ppiwrite()  *  * IEEE1284 compliant write  *  * Actually, this is the peripheral side of a remote IEEE1284 read  *  * The first part of the negociation (IEEE1284 device detection) is  * done at interrupt level, then the remaining is done by the writing  * process  *  * Once negociation done, transfer data  */
argument|static int ppiwrite(dev_t dev, struct uio *uio, int ioflag) {
ifdef|#
directive|ifdef
name|PERIPH_1284
argument|u_int unit = minor(dev); 	struct ppi_data *ppi = UNITOSOFTC(unit); 	device_t ppidev = UNITODEVICE(unit);         device_t ppbus = device_get_parent(ppidev); 	int len
argument_list|,
argument|error =
literal|0
argument_list|,
argument|sent;
if|#
directive|if
literal|0
argument|int ret;
define|#
directive|define
name|ADDRESS
value|MS_PARAM(0, 0, MS_TYP_PTR)
define|#
directive|define
name|LENGTH
value|MS_PARAM(0, 1, MS_TYP_INT)
argument|struct ppb_microseq msq[] = { 		  { MS_OP_PUT, { MS_UNKNOWN, MS_UNKNOWN, MS_UNKNOWN } }, 		  MS_RET(0) 	};
comment|/* negociate ECP mode */
argument|if (ppb_1284_negociate(ppbus, PPB_ECP, 0)) { 		printf("ppiwrite: ECP negociation failed\n"); 	}  	while (!error&& (len = min(uio->uio_resid, BUFSIZE))) { 		uiomove(ppi->ppi_buffer, len, uio);  		ppb_MS_init_msq(msq, 2, ADDRESS, ppi->ppi_buffer, LENGTH, len);  		error = ppb_MS_microseq(ppbus, msq,&ret); 	}
endif|#
directive|endif
comment|/* we have to be peripheral to be able to send data, so 	 * wait for the appropriate state 	 */
argument|if (ppb_1284_get_state(ppbus)< PPB_PERIPHERAL_NEGOCIATION) 		ppb_1284_terminate(ppbus);   	while (ppb_1284_get_state(ppbus) != PPB_PERIPHERAL_IDLE) {
comment|/* XXX should check a variable before sleeping */
ifdef|#
directive|ifdef
name|DEBUG_1284
argument|printf(
literal|"s"
argument|);
endif|#
directive|endif
argument|ppi_enable_intr(ppidev);
comment|/* sleep until IEEE1284 negociation starts */
argument|error = tsleep(ppi, PCATCH | PPBPRI,
literal|"ppiwrite"
argument|,
literal|0
argument|);  		switch (error) { 		case
literal|0
argument|:
comment|/* negociate peripheral side with BYTE mode */
argument|ppb_peripheral_negociate(ppbus, PPB_BYTE,
literal|0
argument|); 			break; 		case EWOULDBLOCK: 			break; 		default: 			goto error; 		} 	}
ifdef|#
directive|ifdef
name|DEBUG_1284
argument|printf(
literal|"N"
argument|);
endif|#
directive|endif
comment|/* negociation done, write bytes to master host */
argument|while ((len = min(uio->uio_resid, BUFSIZE)) !=
literal|0
argument|) { 		uiomove(ppi->ppi_buffer, len, uio); 		if ((error = byte_peripheral_write(ppbus, 						ppi->ppi_buffer, len,&sent))) 			goto error;
ifdef|#
directive|ifdef
name|DEBUG_1284
argument|printf(
literal|"d"
argument|);
endif|#
directive|endif
argument|}  error:
else|#
directive|else
comment|/* PERIPH_1284 */
argument|int error = ENODEV;
endif|#
directive|endif
argument|return (error); }  static int ppiioctl(dev_t dev, u_long cmd, caddr_t data, int flags, struct proc *p) { 	u_int unit = minor(dev); 	device_t ppidev = UNITODEVICE(unit);         device_t ppbus = device_get_parent(ppidev); 	int error =
literal|0
argument|; 	u_int8_t *val = (u_int8_t *)data;  	switch (cmd) {  	case PPIGDATA:
comment|/* get data register */
argument|*val = ppb_rdtr(ppbus); 		break; 	case PPIGSTATUS:
comment|/* get status bits */
argument|*val = ppb_rstr(ppbus); 		break; 	case PPIGCTRL:
comment|/* get control bits */
argument|*val = ppb_rctr(ppbus); 		break; 	case PPIGEPPD:
comment|/* get EPP data bits */
argument|*val = ppb_repp_D(ppbus); 		break; 	case PPIGECR:
comment|/* get ECP bits */
argument|*val = ppb_recr(ppbus); 		break; 	case PPIGFIFO:
comment|/* read FIFO */
argument|*val = ppb_rfifo(ppbus); 		break; 	case PPISDATA:
comment|/* set data register */
argument|ppb_wdtr(ppbus, *val); 		break; 	case PPISSTATUS:
comment|/* set status bits */
argument|ppb_wstr(ppbus, *val); 		break; 	case PPISCTRL:
comment|/* set control bits */
argument|ppb_wctr(ppbus, *val); 		break; 	case PPISEPPD:
comment|/* set EPP data bits */
argument|ppb_wepp_D(ppbus, *val); 		break; 	case PPISECR:
comment|/* set ECP bits */
argument|ppb_wecr(ppbus, *val); 		break; 	case PPISFIFO:
comment|/* write FIFO */
argument|ppb_wfifo(ppbus, *val); 		break; 	case PPIGEPPA:
comment|/* get EPP address bits */
argument|*val = ppb_repp_A(ppbus); 		break; 	case PPISEPPA:
comment|/* set EPP address bits */
argument|ppb_wepp_A(ppbus, *val); 		break; 	default: 		error = ENOTTY; 		break; 	}      	return (error); }  DRIVER_MODULE(ppi, ppbus, ppi_driver, ppi_devclass,
literal|0
argument|,
literal|0
argument|);
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NPPI */
end_comment

end_unit

